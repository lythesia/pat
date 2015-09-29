#!/usr/bin/env ruby

s = "PATest"
c = s.chars.zip(Array.new(6, 0)).to_h
gets.chomp.each_char do |ch|
  c[ch] += 1 if c.has_key? ch
end

until c.empty?  do
  ch, cc = c.each_pair.min_by { |k, v| v }
  if cc > 0
    print s * cc
    c.each { |k, _| c[k] -= cc }
  end
  s = s.delete(ch); c.delete(ch)
end
puts
