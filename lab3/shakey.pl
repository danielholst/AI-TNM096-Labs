% Shakey lab

% Actions

act( go(InRoom, ToRoom),
    [shakey(S), at(S,InRoom), on(S, floor), connected(InRoom, ToRoom)],
    [at(S, InRoom)],
    [at(S, ToRoom)]
    ).

act( climbUp(B),
    [shakey(S), on(S, floor), block(B), at(S, X), at(B, X)],
    [on(S, floor)],
    [on(S, block)]
    ).

act( climbDown(B),
    [shakey(S), block(B), on(S, B), at(S,X), at(B,X)],
    [on(S, block)],
    [on(S, floor)]
    ).

act( pushBox(B, Pos1, Pos2),
    [shakey(S), block(B), connected(Pos1, Pos2), at(S, Pos1), at(B, Pos1), on(S, floor)],
    [at(S, Pos1), at(B, Pos1)],
    [at(S, Pos2), at(B, Pos2)]
    ).

act( turnOn(),
    [shakey(S), switch(L), block(B), at(B, X), on(S, block), at(S, X), at(L, X), lightOn(X, false)],
    [lightOn(L, false)],
    [lightOn(L, true)]
    ).

act( turnOff(),
    [shakey(S), block(B), at(B, X), on(S, block), at(S, X), lightOn(X, true)],
    [lightOn(X, true)],
    [lightOn(X, false)]
    ).

% Goal state
goal_state( [
    lightOn(room1_switch, false)
    %at(block2, room2)
    %at(s, room1)
    ]).

% Initial state
initial_state( [

    % init state of shakey
    shakey(s),
    at(s, room3),
    on(s, floor),

    % connected rooms
    connected(room1, corridor),
    connected(room2, corridor),
    connected(room3, corridor),
    connected(room4, corridor),
    connected(corridor, room1),
    connected(corridor, room2),
    connected(corridor, room3),
    connected(corridor, room4),

    connected(room1, room1_switch),
    connected(room2, room2_switch),
    connected(room3, room3_switch),
    connected(room4, room4_switch),

    connected(room1_switch, room1),
    connected(room2_switch, room2),
    connected(room3_switch, room3),
    connected(room4_switch, room4),

    % Lighs
    lightOn(room1_switch, true),
    lightOn(room2_switch, false),
    lightOn(room3_switch, false),
    lightOn(room4_switch, true),

    % blocks
    block(block1),
    block(block2),
    block(block3),
    block(block4),
    at(block1, room1),
    at(block2, room1),
    at(block3, room1),
    at(block4, room1)
    ]).



