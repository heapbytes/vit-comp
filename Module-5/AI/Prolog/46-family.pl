% Facts [ dont blindly replace char to names, me gpt use kelay coresponding words aren't accurate lol.]
male(a).
male(b).
male(c).
male(d).
male(e).
male(f).
male(g).
male(h).
male(i).
male(j).
male(k).

female(l).
female(m).
female(n).
female(o).
female(p).
female(q).
female(r).
female(s).
female(t).
female(u).
female(v).
female(w).

% Parent relations
parent(a,b).
parent(a,c).
parent(a,d).
parent(a,v).
parent(a,p).
parent(b,g).
parent(b,h).
parent(c,i).
parent(c,j).
parent(d,k).
parent(d,l).
parent(e,q).
parent(e,r).
parent(f,s).
parent(g,t).
parent(l,b).
parent(l,c).
parent(l,d).
parent(l,v).
parent(l,p).
parent(m,g).
parent(n,i).
parent(o,j).
parent(p,t).
parent(p,u).
parent(q,k).
parent(r,l).


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
