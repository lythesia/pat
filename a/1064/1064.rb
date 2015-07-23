#!/usr/bin/env ruby

def dfs(i)
  return if i > $n
  l, r = 2*i, 2*i + 1
  dfs(l)
  $ans[i] = $a[$tot]; $tot += 1
  dfs(r)
end

$n = gets.chomp.to_i
$a = gets.split.map &:to_i
$ans, $tot = Array.new($n + 1, 0), 0
$a.sort!
dfs(1)
puts $ans.drop(1) * ' '
