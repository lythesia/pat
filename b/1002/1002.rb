#!/usr/bin/env ruby

t = {
  '0' => 'ling',
  '1' => 'yi',
  '2' => 'er',
  '3' => 'san',
  '4' => 'si',
  '5' => 'wu',
  '6' => 'liu',
  '7' => 'qi',
  '8' => 'ba',
  '9' => 'jiu'
}
n = gets.chomp
sum = n.chars.map(&:to_i).reduce(&:+).to_s
ans = sum.chars.map { |c| t[c] }
puts ans.join ' '
