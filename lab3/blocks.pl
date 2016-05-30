% Blocks World

:- use_module(library(clpfd)).

pickable(X) :- X in 1..6.
block(X) :- X in 2..4 \/ 6.
triangle(X) :- X in 1 \/ 5.
table(X) :- X in 7.

blue(X) :- X in 3 \/ 6.
green(X) :- X in 2 \/ 5.
red(X) :- X in 1 \/ 4.

act( pickup_from_table(X),
    [gripEmpty, onTop(X), on(X, 7)],
    [gripEmpty, on(X, 7)],
    [holding(X)]
    ):-
pickable(X).

act( pickup_from_block(X,Y),
    [gripEmpty, onTop(X), on(X, Y)],
    [gripEmpty, on(X, Y)],
    [holding(X), onTop(Y)]
    ):-
pickable(X).

act( putdown_on_table(X),
    [holding(X)],
    [holding(X)],
    [gripEmpty, on(X,7)]
    ):-
pickable(X).

act( putdown_on_block(X, Y),
    [onTop(Y), holding(X)],
    [onTop(Y), holding(X)],
    [gripEmpty, on(X,Y)]
    ):-
pickable(X),
block(Y).


goal_state([
    on(X, Y),
    on(Y,Z),
    on(Z,7)
    ]):-
green(Y),
blue(Z).

initial_state([
    gripEmpty,
    on(1,7),
    on(2,7),
    on(4,7),
    on(6,7),
    on(3,4),
    on(5,6),

    onTop(1),
    onTop(2),
    onTop(3),
    onTop(5)

]).
