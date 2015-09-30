#!/usr/bin/env ruby

n = gets.chomp.to_i
chd = Array.new(n) { [nil, nil] }
fa = Array.new(n, true)
n.times do |i|
  lr = gets.chomp.split
  lr.each_with_index do |x, j|
    if x != '-'
      x = x.to_i
      chd[i][1 - j] = x; fa[x] = false
    end
  end
end
root = fa.index true

ans = []
q = Queue.new; q << root
until q.empty?
  t = q.pop; ans << t 
  q << chd[t][0] if chd[t][0]
  q << chd[t][1] if chd[t][1]
end
puts ans * ' '

ans = []
iter = ->(r) { if r; iter.call(chd[r][0]); ans << r; iter.call(chd[r][1]); end }
iter.call root
puts ans * ' '
