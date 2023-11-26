go :- check(Animal),
      write('I guess that the animal is: '),
      write(Animal), nl, undo.

check(cheetah) :- cheetah, !.
check(tiger) :- tiger, !.
check(dog) :- dog, !.
check(giraffe) :- giraffe, !.
check(zebra) :- zebra, !.
check(ostrich) :- ostrich, !.
check(penguin) :- penguin, !.
check(unknown).

cheetah :- mammal, carnivore, verify(has_tawny_color), verify(has_dark_spots).
tiger :- mammal, carnivore, verify(has_tawny_color), verify(has_black_stripes).
dog :- mammal, verify(has_fur), verify(has_tail), verify(is_domesticated).
giraffe :- ungulate, verify(has_long_neck), verify(has_long_legs).
zebra :- ungulate, verify(has_black_stripes).
ostrich :- bird, verify(does_not_fly), verify(has_long_neck).
penguin :- bird, verify(does_not_fly), verify(swims), verify(is_black_and_white).

mammal :- verify(has_hair), !.
mammal :- verify(gives_milk), !.
bird :- verify(has_feathers), !.
bird :- verify(flys), verify(lays_eggs).
carnivore :- verify(eats_meat), !.
carnivore :- verify(has_pointed_teeth), verify(has_claws), verify(has_forward_eyes).
ungulate :- mammal, verify(has_hooves), !.
ungulate :- mammal, verify(chews_cud).

ask(Question) :- write('Does the animal have the following attribute: '), 
                 write(Question), write('? '), read(Response), nl, 
                 ( (Response == yes ; Response == y) -> assert(yes(Question)) ; assert(no(Question)), fail).

:- dynamic yes/1, no/1.

verify(S) :- (yes(S) -> true ; (no(S) -> fail ; ask(S))).

undo :- retract(yes(_)), fail.
undo :- retract(no(_)), fail.
undo.

