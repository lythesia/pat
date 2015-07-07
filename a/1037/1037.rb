#!/usr/bin/env ruby

# case 4 TLE
cp = [Array.new, Array.new]
p, n = [0, 0], [0, 0]
2.times do |i|
  gets
  gets.chomp.split.each do |x|
    x = x.to_i
    cp[i] << x
    if x > 0
      p[i] += 1
    elsif x < 0
      n[i] += 1
    end
  end
end
cp[0].sort!; cp[1].sort!
minp, minn = p.min, n.min
ans = 0
1.upto(minp) { |i| ans += cp[0][-i] * cp[1][-i]}
0.upto(minn - 1) { |i| ans += cp[0][i] * cp[1][i]}
puts ans
