insect(ant, small, brown, six_legs, no_wings, social, ground).
insect(ant, small, black, six_legs, no_wings, social, ground).
insect(bee, small, yellow, six_legs, two_wings, social, flowers).
insect(butterfly, small, colorful, six_legs, two_wings, solitary, gardens).
insect(spider, tiny, brown, eight_legs, no_wings, solitary, house).
insect(ladybug, small, red, six_legs, two_wings, solitary, plants).
insect(mosquito, small, gray, six_legs, two_wings, solitary, wetlands).
insect(grasshopper, medium, green, six_legs, two_wings, solitary, grassy_fields).
insect(beetle, small, black, six_legs, two_wings, solitary, forests).
insect(praying_mantis, medium, green, six_legs, two_wings, solitary, gardens).
insect(dragonfly, medium, iridescent, six_legs, two_wings, solitary, ponds).
insect(centipede, medium, brown, many_legs, no_wings, solitary, dark_damp_places).
insect(fly, small, black, six_legs, two_wings, solitary, various).
insect(wasp, small, black_and_yellow, six_legs, two_wings, solitary, nests).
insect(ant, small, red, six_legs, no_wings, social, ground).
insect(bumblebee, medium, black_and_yellow, six_legs, two_wings, social, flowers).
insect(damselfly, small, blue, six_legs, two_wings, solitary, ponds).
insect(firefly, small, bioluminescent, six_legs, two_wings, solitary, fields).
insect(earwig, small, dark_brown, six_legs, two_wings, solitary, dark_damp_places).

identify_insect(Color, Size, Legs, Wings, Social, Habitat, Insect) :-
    insect(Insect, Size, Color, Legs, Wings, Social, Habitat).

start :-
    write('Welcome to the Insect Identifier!'), nl,
    write('Please describe the insect you want to identify.'), nl,
    write('What is the color of the insect? '), read(Color), nl,
    write('What is the size of the insect (small, medium, large)? '), read(Size), nl,
    write('How many legs does the insect have? (six_legs, eight_legs or many_legs?)'), read(Legs), nl,
    write('How many wings does the insect have? (two_wings or no_wings)? '), read(Wings), nl,
    write('Is the insect social (social or solitary)? '), read(Social), nl,
    write('Where is the insect commonly found (e.g., "forests," "flowers", "various")? '), read(Habitat), nl,
    identify_insect(Color, Size, Legs, Wings, Social, Habitat, Insect),
    (
        Insect \= [] -> write('Based on your description, the insect may be a '), write(Insect), nl
        ; write('No insect identified based on your given information'), nl
    ).