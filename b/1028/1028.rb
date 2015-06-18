#!/usr/bin/env ruby

# case 4 172 ms OTZ
ans = []
n = gets.chomp.to_i
n.times { ans << gets.chomp.split }
ans = ans.select { |_, date| date >= "1814/09/06" and date <= "2014/09/06" }
if ans.empty?
  puts 0
else
  puts "#{ans.length} #{ans.minmax_by { |_, date| date }.map(&:first) * ' ' }"
end
