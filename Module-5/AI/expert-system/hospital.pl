:- dynamic yes/1, no/1.

ask(Question) :-
    write('Does the patient have symptom: '),
    write(Question),
    write('? '),
    read(Response),
    nl,
    ((Response == yes ; Response == y) ->
        assert(yes(Question)) ;
        assert(no(Question)), fail).

ask_history(Question) :-
    write('Does the patient have a history of: '),
    write(Question),
    write('? '),
    read(Response),
    nl,
    ((Response == yes ; Response == y) ->
        assert(yes(Question)) ;
        assert(no(Question)), fail).

ask_blood(Question) :-
    write('Does the patient have pump blood level between 80-120: '),
    write(Question),
    write('? '),
    read(Response),
    nl,
    ((Response == yes ; Response == y) ->
        assert(yes(Question)) ;
        assert(no(Question)), fail).

verify(S) :-
    (yes(S) ->
        true ;
    (no(S) ->
        fail ;
    ask(S))).

verify_history(S) :-
    (yes(S) ->
        true ;
    (no(S) ->
        fail ;
    ask_blood(S))).

verify_blood(S) :-
    (yes(S) ->
        true ;
    (no(S) ->
        fail ;
    ask_history(S))).

verify_diabetes(S) :-
    (yes(S) ->
        true ;
    (no(S) ->
        fail ;
    ask_blood(S))).

% Symptoms
symptom(headache).
symptom(runny_nose).
symptom(sneezing).
symptom(sore_throat).
symptom(fever).
symptom(chills).
symptom(body_ache).
symptom(abdominal_pain).
symptom(poor_appetite).
symptom(rash).
symptom(conjunctivitis).
symptom(sweating).
symptom(nausea).
symptom(vomiting).
symptom(diarrhea).
symptom(polydipsia).
symptom(polyuria).

% Diseases
disease(cold, [headache, runny_nose, sneezing, sore_throat]).
disease(allergy, [headache, runny_nose]).
disease(flu, [headache, fever, chills, body_ache]).
disease(typhoid, [headache, abdominal_pain, poor_appetite, fever]).
disease(measles, [fever, runny_nose, rash, conjunctivitis]).
disease(malaria, [fever, sweating, headache, nausea, vomiting, diarrhea]).
disease(fever, [fever]).
disease(diabetes, [polydipsia, polyuria]).
disease(no_disease, []).

undo :- retractall(yes(_)), retractall(no(_)).

% Entry point for diagnosis
diagnose(Disease) :-
    disease(Disease, Symptoms),
    verify_symptoms(Symptoms),
    ((Disease == diabetes) ->
        verify_diabetes(diabetes) ;
        verify_history(Disease)),
    write('Based on the symptoms and history, I believe the patient may have '),
    write(Disease),
    nl,
    write('TAKE CARE '),
    undo.

verify_symptoms([]).
verify_symptoms([Symptom | Rest]) :-
    verify(Symptom),
    verify_symptoms(Rest).
