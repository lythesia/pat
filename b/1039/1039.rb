#!/usr/bin/env ruby

a = Array.new(128, 0)
yes, no = 0, 0
gets.chomp.each_char { |c| a[c.ord] += 1; yes += 1 }
gets.chomp.each_char do |c|
  if a[c.ord] > 0
    a[c.ord] -= 1; yes -= 1
  else
    no += 1
  end
end
no > 0 ? puts("No #{no}") : puts("Yes #{yes}")
