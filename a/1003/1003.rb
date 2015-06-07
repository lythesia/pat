#!/usr/bin/env ruby

require 'set'
INF = 0x3f3f3f3f

n, m, c1, c2 = gets.split.map(&:to_i)
team = gets.split.map(&:to_i)
edge = []
n.times { |i| edge << [] }
dist = Array.new n, INF
resc = Array.new n, 0
cnts = Array.new n, 0
vist = Array.new n, false
m.times do
  x, y, d = gets.split.map(&:to_i)
  edge[x] << [y, d]
  edge[y] << [x, d]
end
# dijkstra
dist[c1], resc[c1], cnts[c1] = 0, team[c1], 1
0.upto(n-1) do
  _, x = dist.each_with_index.select { |x, i| !vist[i] and x != INF }.min
  break if x.nil?
  edge[x].each do |y, d|
    next if vist[y]
    dy = dist[x] + d
    if dy < dist[y]
      dist[y], resc[y], cnts[y] = dy, resc[x] + team[y], cnts[x]
    elsif dy == dist[y]
      resc[y] = [ resc[x]+team[y], resc[y] ].max
      cnts[y] += cnts[x]
    end
  end
  vist[x] = true
end
puts "#{cnts[c2]} #{resc[c2]}"
