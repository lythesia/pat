#!/usr/bin/env ruby

_, *an = gets.chomp.split
_, *bn = gets.chomp.split
c = Array.new 2005, 0.0
an.each_slice(2) do |ae, ac|
  bn.each_slice(2) do |be, bc|
    c[ae.to_i + be.to_i] += ac.to_f * bc.to_f
  end
end
print c.count { |x| x != 0.0 }
2000.downto(0) do |i|
  printf " %d %.1f", i, c[i] if c[i] != 0.0
end
puts
