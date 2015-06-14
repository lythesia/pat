#!/usr/bin/env ruby

# case 5 TLE
rule = {'B' => 0, 'J' => 1, 'C' => 2}
n = gets.chomp.to_i
ans = [0, 0, 0]
ac = {'B' => 0, 'C' => 0, 'J' => 0}
bc = ac.dup
n.times do
  a, b = gets.chomp.split
  if a == b
    ans[1] += 1
  else
    if rule[a] == (rule[b] + 1) % 3
      ans[0] += 1
      ac[a] += 1
    else
      ans[2] += 1
      bc[b] += 1
    end
  end
end
wa = ac.max_by { |k, v| v }[0]
wb = bc.max_by { |k, v| v }[0]

puts ans * ' '
puts ans.reverse * ' '
puts [wa, wb] * ' '
