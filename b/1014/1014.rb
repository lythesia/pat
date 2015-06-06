#!/usr/bin/env ruby

day = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
ans = []
2.times do
  s = []
  2.times { s << gets.chomp }
  a, b = *s
  0.upto(s.map(&:length).min - 1) do |i|
    if a[i] == b[i]
      if ans.empty?
        ans << day[a[i].ord - 'A'.ord] if a[i] =~ /[A-G]/
      elsif ans.length == 1
        ans << (a[i] =~ /[0-9]/ ? a[i].to_i : a[i].ord - 'A'.ord + 10) if a[i] =~ /[0-9A-N]/
      elsif ans.length == 2
        ans << i if a[i] =~ /[a-z]/i
      end
    end
  end
end
puts "%s %02d:%02d" % ans
