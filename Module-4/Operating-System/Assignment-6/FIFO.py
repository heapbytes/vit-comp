#!/bin/env python3

def FIFO(input_ , pg_frame_count):
    
    change = 0
    hit, fault = 0, 0
    frames = []
    print('\nInput \t Frames')

    for i in input_ :
        if(len(frames) < pg_frame_count):
            if i not in frames:
                frames.append(i)
                print(i, ' \t*', [j for j in frames])
                fault += 1
            else:
                print(i, ' \t ', [j for j in frames])
                hit += 1
        else:
            if i not in frames:
                frames[change] = i
                print(i, ' \t*', [j for j in frames])
                change = (change +1) % pg_frame_count
                fault += 1
            else:
                print(i, ' \t ', [j for j in frames])
                hit += 1

    return hit, fault

if __name__ == '__main__':
    input_ = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0]
    pg_frame_count = int(input("Enter page frame count : "))
    hit, fault = FIFO(input_, pg_frame_count)
    print(f'\nFor the given input: \n{input_}\n\nTotal hits = {hit}\nFault = {fault}')
