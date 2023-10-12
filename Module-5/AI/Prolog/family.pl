% Facts
father(Balaji, Gourav).
father(Balaji, Aishwarya).
father(Balaji, Vimala).

mother(Veena, Gourav).
mother(Veena, Aishwarya).
mother(Veena, Vimala).



% Rules
parent(X, Y) :- father(X, Y).
parent(X, Y) :- mother(X, Y).

