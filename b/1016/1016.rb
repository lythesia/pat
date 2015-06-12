#!/usr/bin/env ruby

a, da, b, db = gets.chomp.split
pa = (da * a.count(da)).to_i
pb = (db * b.count(db)).to_i
puts pa + pb
