.name "test"
.comment "testing fncs"
live:%
live %3

ld 34,r3
ld %34,r3

st r2,34
st r2,r4

add r1,r1,r1

sub r1,r1,r1

and r1, r1, r2
and 34, r1, r2
and %34, r1, r2
and r1, 34, r2
and 34, 34, r2
and %34, 34, r2
and r1, %34, r2
and 34, %34, r2
and %34, %34, r2

or r1, r1, r2
or 34, r1, r2
or %34, r1, r2
or r1, 34, r2
or 34, 34, r2
or %34, 34, r2
or r1, %34, r2
or 34, %34, r2
or %34, %34, r2

xor r1, r1, r2
xor 34, r1, r2
xor %34, r1, r2
xor r1, 34, r2
xor 34, 34, r2
xor %34, 34, r2
xor r1, %34, r2
xor 34, %34, r2
xor %34, %34, r2

zjmp %34

ldi r3, r1, r2
ldi 34, r1, r2
ldi %34, r1, r2
ldi r3, %34, r2
ldi 34, %34, r2
ldi %34, %34, r2

sti r1, r1, %34
sti r1, %12, %34
sti r1, 42, %34
sti r1, r1, r3
sti r1, %12, r3
sti r1, 42, r3

fork %34

lld 34,r3
lld %34,r3

lldi r3, r1, r2
lldi 34, r1, r2
lldi %34, r1, r2
lldi r3, %34, r2
lldi 34, %34, r2
lldi %34, %34, r2

lfork %34

aff r1