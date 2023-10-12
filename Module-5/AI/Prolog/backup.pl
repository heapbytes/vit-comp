male(pentappa).
male(balaji).
male(gourav).
male(abhishek).
male(vedant).
male(dashrat).

female(veena).
female(aishwarya).
female(vimala).
female(anusaya).
female(rekha).
female(chandana).
female(pranoti).

father(d,a).
father(d,u).
father(d,q).
father(d,y).
father(a,v).
father(a,r).
father(y,b).
father(y,e).
father(v,z).
father(b,f).
father(b,g).
father(f,h).

mother(s,a).
mother(s,u).
mother(s,y).
mother(s,q).
mother(u,v).
mother(u,r).
mother(q,b).
mother(q,e).
mother(r,z).
mother(e,f).
mother(e,g).
mother(g,h).

wife(s,d).
wife(u,a).
wife(q,y).
wife(r,v).
wife(e,b).
wife(g,f).

parent(d,s,a).
parent(d,s,u).
parent(d,s,y).
parent(d,s,q).
parent(a,u,v).
parent(a,u,r).
parent(y,q,b).
parent(y,q,e).
parent(v,r,z).
parent(b,e,f).
parent(b,e,g).
parent(f,g,h).

sister(X,Y):-parent(A,B,X),parent(A,B,Y),female(X),X\==Y.
brother(X,Y):-parent(A,B,X),parent(A,B,Y),male(X),X\==Y.
sibilings(X,Y):-parent(A,B,X),parent(A,B,Y),X\==Y.
husband(X,Y):-wife(Y,X).
son(X,Y):-father(Y,X);mother(Y,X);male(X).
daughter(X,Y):-father(Y,X);mother(Y,X),female(X).
uncle(X,Y):-brother(Z,X),father(Z,Y).
aunt(X,Y):-husband(Z,X),uncle(Z,Y).
cousin(X,Y):-uncle(Z,X),father(Z,Y).
