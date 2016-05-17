% Shakey lab

% Actions

act( go(InRoom, ToRoom),
    [shakey(S), at(S,InRoom), connected(InRoom, ToRoom)],
    [at(S, InRoom)],
    [at(S, ToRoom)]
    ).

act( climbUp(B),
    [shakey(S), on(S, floor), block(B), at(S, X), at(B, X)],
    [on(S, floor)],
    [on(S, B)]
    ).

act( climbDown(B),
    [shakey(S), block(B), on(S, B), at(S,X), at(B,X)],
    [on(S, B)],
    [on(S, floor)]
    ).

act( pushBox(Box, Pos1, Pos2),
[shakey(S), at(S, Pos1), at(Box, Pos1), lightOn(Pos1, true), on(S, floor)],
[at(S, Pos1), at(Box, Pos1)],
[at(S, Pos2), at(Box, Pos2)]
).

% Goal state
goal_state( [on(s, block1)] ).

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

    % swithces
    connected(room1, room1_switch),
    connected(room2, room2_switch),
    connected(room3, room3_switch),
    connected(room4, room4_switch),

    % Lighs
    lightOn(room1, true),
    lightOn(room2, false),
    lightOn(room3, false),
    lightOn(room4, true),

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



