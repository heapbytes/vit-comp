#!/bin/env python3

def replace(inp, frames):    
    #input_ = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1]
    less = 0
    print("FRAMES : ", frames)
    for i in frames:
        less = inp.index(i) if inp.index(i) < less else less
    
    return less

def LRU(inp , pg_frame_count):

    change = 0
    hit, fault = 0, 0
    frames = []
    print('\nInput \t Frames')
    counter = 0
    for i in inp:
        counter += 1
        if(len(frames) < pg_frame_count):
            if i not in frames:
                frames.append(i)
                fault += 1
            else:
                hit += 1
        else:
            if i in frames:
                hit += 1
            else:
                change = replace(inp[:counter], frames)
                print(change)
    return 1, 1

if __name__ == '__main__':
    #input_ = '7 0 1 2 0 3 0 4 2 3 0 3 2'.split(' ')
    input_ = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1]
    pg_frame_count = int(input("Enter page frame count : "))
    hit, fault = LRU(input_, pg_frame_count)
    print(f'\nFor the given input: \n{input_}\n\nTotal hits = {hit}\nFault = {fault}')


'''

    for i in range(len(input_)+1):
        new_inp = input_[:i+1]
        if(len(frames) < pg_frame_count):
            if input_[i] not in frames:
                frames.append(input_[i])
                print(i, ' \t*', [j for j in frames])
                fault += 1
            else:
                print(i, ' \t ', [j for j in frames])
                hit += 1
        else:
            if i not in frames:
                #new_inp = input_[:i+1]
                print("NeW EW : ", new_inp)
                change = replace(new_inp, frames)
                frames[frames.index(new_inp[change])] = i
                print(i, ' \t*', [j for j in frames])
                fault += 1
            else:
                print(i, ' \t ', [j for j in frames])
                hit += 1
    return hit, fault 

'''
