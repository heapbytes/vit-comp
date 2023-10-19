% Define rules for different classes of animals based on characteristics
mammal(X) :- has_fur_or_hair(X), is_warm_blooded(X), \+lays_eggs(X).
bird(X) :- has_feathers(X), lays_eggs(X), \+is_warm_blooded(X).
reptile(X) :- has_scales(X), lays_eggs(X), \+is_warm_blooded(X).
fish(X) :- has_scales(X), lays_eggs(X), \+has_lungs(X).

% Define characteristics
has_fur_or_hair(X) :- ask(X, 'Does it have fur or hair?').
can_fly(X) :- ask(X, 'Can it fly?').
lays_eggs(X) :- ask(X, 'Does it lay eggs?').
is_warm_blooded(X) :- ask(X, 'Is it warm-blooded?').
has_scales(X) :- ask(X, 'Does it have scales?').
has_feathers(X) :- ask(X, 'Does it have feathers?').
has_lungs(X) :- ask(X, 'Does it have lungs?').

% Ask questions for a specific animal
ask(X, Question) :-
    write(Question),
    write(' for '), write(X), write('? (yes/no): '),
    read(Answer),
    Answer = yes.

% Main function to classify the animal
classify_animal(X) :-
    (mammal(X) -> write(X), write(' is a mammal.');
    bird(X) -> write(X), write(' is a bird.');
    reptile(X) -> write(X), write(' is a reptile.');
    fish(X) -> write(X), write(' is a fish.');
    write('Sorry, the classification for '), write(X), write(' is not available.')),
    nl.

% Start the expert system by asking questions for a specific animal
start :-
    write('Enter the name of the animal you want to classify: '),
    read(Animal),
    classify_animal(Animal),
    write('Want to classify another animal? (yes/no): '),
    read(Answer),
    Answer = yes,
    start.
start :-
    write('Goodbye!').

% To start the expert system, run the following command:
% start.

