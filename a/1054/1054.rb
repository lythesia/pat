#!/usr/bin/env ruby

# case 2 TLE
cnt, prev = 0, -1
_, n = gets.split.map &:to_i
n.times do
  gets.split.map(&:to_i).each do |c|
    if cnt == 0 || c == prev
      cnt, prev = cnt + 1, c
    else
      cnt -= 1
    end
  end
end
puts prev
