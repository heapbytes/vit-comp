% Facts
male(pentappa).
male(dashrat).
male(arvind).
male(malikarjun).
male(balaji).
male(srinivas).
male(vedant).
male(milind).
male(abhishek).
male(gourav).
male(vijay).

female(anusaya).
female(chandana).
female(uma).
female(lata).
female(veena).
female(rekha).
female(pranoti).
female(neeta).
female(monika).
female(lavanya).
female(aishwarya).
female(asmita).

% Parent relations
parent(pentappa,dashrat).
parent(pentappa,arvind).
parent(pentappa,malikarjun).
parent(pentappa,veena).
parent(pentappa,rekha).
parent(dashrat,vedant).
parent(dashrat,pranoti).
parent(arvind,milind).
parent(arvind,lavanya).
parent(malikarjun,neeta).
parent(malikarjun,monika).
parent(balaji,gourav).
parent(balaji,aishwarya).
parent(srinivas,abhishek).
parent(vijay,asmita).
parent(anusaya,dashrat).
parent(anusaya,arvind).
parent(anusaya,malikarjun).
parent(anusaya,veena).
parent(anusaya,rekha).
parent(chandana,vedant).
parent(chandana,pranoti).
parent(uma,milind).
parent(uma,lavanya).
parent(lata,neeta).
parent(lata,monika).
parent(veena,gourav).
parent(veena,aishwarya).
parent(rekha,abhishek).
parent(lavanya,asmita).


mother(X,Y) :- parent(X,Y), female(X).
father(X,Y) :- parent(X,Y), male(X).

wife(X,Y) :- female(X), male(Y), parent(X,Z), parent(Y,Z), X \= Y.
husband(X,Y) :- male(X), female(Y), parent(X,Z), parent(Y,Z), X \= Y.

grandparent(X,Z) :- parent(X,Y), parent(Y,Z).
grandmother(X,Z) :- parent(X,Y), parent(Y,Z), female(X).
grandfather(X,Z) :- parent(X,Y), parent(Y,Z), male(X).

uncle(X,Y) :- parent(P,Y), sibling(X,P), male(X).
aunt(X,Y) :- parent(P,Y), sister(X,P).

sibling(X,Y) :- parent(P,X), parent(P,Y),X \= Y.
cousin(X,Y) :- parent(P1,X), parent(P2,Y), sibling(P1,P2), X \= Y.
sister(X,Y) :- female(X), sibling(X,Y).
brother(X,Y) :- male(X), sibling(X,Y).

fatherinlaw(X,Y) :- wife(Z,Y), father(X,Z),male(Y).
motherinlaw(X,Y) :- wife(Z,Y), mother(X,Z),male(Y).
brotherinlaw(X,Y) :- wife(Z,Y), brother(X,Z),male(Y).

niece(X,Y) :- female(X), mother(Z,X), sister(Z,Y).
nephew(X,Y) :- male(X), mother(Z,X), sister(Z,Y).

greatgrandfather(X,Y) :- male(X), grandparent(_, Y).
greatgrandmother(X,Y) :- female(X), grandparent(_, Y).


soninlaw(X,Y) :- male(Y), wife(Z,Y), parent(X,Z).
