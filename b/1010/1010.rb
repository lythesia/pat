#!/usr/bin/env ruby

ans = []
gets.split.map(&:to_i).each_slice(2) { |c, e| ans << c * e << e - 1 if e != 0 }
ans << 0 << 0 if ans.empty?
puts ans * ' '
