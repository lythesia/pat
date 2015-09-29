#!/usr/bin/env ruby

c = Array.new(26, 0)
gets.chomp.each_char do |ch|
  c[ch.downcase.ord - 97] += 1 if ch =~ /[A-Za-z]/
end
ans = c.each_with_index.max_by { |x, i| [x, -i] }
puts "#{(ans[1] + 97).chr} #{ans[0]}"
