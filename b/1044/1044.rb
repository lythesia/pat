#!/usr/bin/env ruby

b1 = %w[tret jan feb mar apr may jun jly aug sep oct nov dec]
b2 = %w[fuck tam hel maa huh tou kes hei elo syy lok mer jou]

n = gets.chomp.to_i
n.times do
  s = gets.chomp
  ans = []
  if s =~ /\d+/
    en = s.to_i
    i = 0
    while en > 0
      ans << en % 13
      en /= 13
    end
    ans << 0 if ans.empty?
    ans.reverse!
    mn = []
    if ans.size == 1
      mn << b1[ans.first]
    else
      mn << b2[ans.first]
    end
    ans.drop(1).each do |x|
      mn << b1[x] if x > 0 # no tert at lower digits
    end
    puts mn * ' '
  else
    mn = s.split
    ans = []
    if mn.size == 1
      if b2.include? mn.first
        ans << b2.index(mn.first)
        ans << 0
      else
        ans << b1.index(mn.first)
      end
    else
      ans << b2.index(mn.first)
    end
    mn.drop(1).each do |x|
      ans << b1.index(x)
    end
    en = ans.inject(0) { |acc, x| acc * 13 + x }
    puts en
  end
end
