.name "zork"
.comment "example"

sti r1,%:live,%4
and r1,%0,r1
live: live %1
zjmp %:live
