#!/usr/bin/env ruby

# case 4: 132 ms vs (42 ms of cpp), まあ、10倍じゃないよねー
tab = []
5.times do
  tab << Hash.new { |h, k| h[k] = [] }
end
n = gets.chomp.to_i
n.times do
  id = gets.chomp
  title = gets.chomp
  author = gets.chomp
  key = gets.chomp.split
  pub = gets.chomp
  year = gets.chomp
  tab[0][title] << id
  tab[1][author] << id
  key.each { |x| tab[2][x] << id }
  tab[3][pub] << id
  tab[4][year] << id
end
tab.each do |t|
  t.each_pair { |k, v| v.sort! }
end
m = gets.chomp.to_i
m.times do
  opt, q = gets.chomp.split ": "
  puts "#{opt}: #{q}"
  if !tab[opt.to_i - 1].has_key? q
    puts "Not Found"
  else
    tab[opt.to_i - 1][q].each { |x| puts x }
  end
end
