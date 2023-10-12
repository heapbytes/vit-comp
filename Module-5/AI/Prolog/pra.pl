male(narayan).
male(prabhakar).
male(krushna).
male(dhananjay).
male(prathamesh).
male(makarand).

female(shantai).
female(sangita).
female(shindu).
female(shillpa).
female(vrushali).
female(sakshi).
female(divya).

father(narayan,prabhakar).
father(narayan,krushna).
father(narayan,dhananjay).
father(prabhakar,prathamesh).
father(prabhakar,vrushali).
father(krushna,makarand).
father(krushna,divya).
father(dhananjay,sakshi).

mother(shantai,prabhakar).
mother(shantai,krushna).
mother(shantai,dhananjay).
mother(sangita,prathamesh).
mother(sangita,vrushali).
mother(shindu,makarand).
mother(shindu,divya).
mother(shillpa,sakshi).

wife(shantai,narayan).
wife(sangita,prabhakar).
wife(shindu,krushna).
wife(shillpa,dhananjay).

sibling(X,Y) :-parent(Z,X),parent(Z,Y),X\=Y.
grandparent(X,Z) :-parent(X,Y),parent(Y,Z).
mother(X,Y):-parent(X,Y),female(X).
father(X,Y):-parent(X,Y),male(X).
uncle(X,Y):-sibling(X,P),parent(P,Y),male(X).
cousin(X,Y):-father(P,X),uncle(P,Y).
aunt(X,Y):-cousin(Y,Z),mother(X,Z).
sister(X,Y):-female(X),parent(P,X),parent(P,Y).
niece(X,Y):-female(X),parent(Z,X),sibling(Z,Y).
daughterinlaw(X,Y):-female(X),wife(X,Z),parent(Y,Z).
