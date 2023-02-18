#!/bin/env python3

def replace(inp, frames):    
    
    ff = []
    for i in frames:
        if i not in inp:
            return i
    
    for i in inp:
        if i not in ff and i in frames:
            ff.append(i)
        else:
            pass
    return ff[-1]

def Optimal(inp , pg_frame_count):

    change = 0
    hit, fault = 0, 0
    frames = []
    print('\nInput \t Frames')
    counter = 0
    for i in inp:
        counter += 1
        new_inp = inp[counter:]
        if(len(frames) < pg_frame_count):
            if i not in frames:
                frames.append(i)
                print(i, ' \t*', [j for j in frames])
                fault += 1
            else:
                print(i, ' \t' , [j for j in frames])
                hit += 1
        else:
            if i in frames:
                print(i, ' \t ', [j for j in frames])
                hit += 1
            else:
                change = replace(new_inp, frames)
                frames[frames.index(change)] = i
                print(i, ' \t*', [j for j in frames])
                fault += 1

    return hit, fault

if __name__ == '__main__':

    input_ = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1]
    pg_frame_count = int(input("Enter page frame count : "))
    hit, fault = Optimal(input_, pg_frame_count)
    print(f'\nFor the given input: \n{input_}\n\nTotal hits = {hit}\nFault = {fault}')

