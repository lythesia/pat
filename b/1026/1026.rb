#!/usr/bin/env ruby

TICK = 100
c1, c2 = gets.split.map &:to_i
ss = (1.0 * (c2 - c1) / TICK).round
hh = ss / 3600
mm = (ss - hh * 3600) / 60
puts "%02d:%02d:%02d" % [hh, mm, ss % 60]
