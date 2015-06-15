#!/usr/bin/env ruby

INF = 0x3f3f3f3f
$d, $v, $p = [], [], []
$send, $back, $path = INF, INF, []
def dfs(x, k, r, b)
  return if k > $d[$sp]
  if x == $sp and k == $d[$sp]
    $send, $back, $path = r, b, $p.dup if r < $send or (r == $send and b < $back)
    return
  end
  $e[x].each do |y, len|
    next if $v[y]
    dy, need, given = k + len, $c - $s[y], b
    $v[y] = true
    $p << y
    if need > given
      dfs(y, dy, r + need - given, 0)
    else
      dfs(y, dy, r, given - need)
    end
    $p.pop
    $v[y] = false
  end
end
$c, n, $sp, m = gets.split.map(&:to_i)
$c >>= 1
$e = Array.new(n+1) { Array.new }
$s = gets.split.map(&:to_i)
$s.unshift 0
m.times do
  x, y, d = gets.split.map(&:to_i)
  $e[x] << [y, d]
  $e[y] << [x, d]
end

q, inq = [0], []
$d[0], inq[0] = 0, true
while !q.empty?
  x = q.shift
  $e[x].each do |y, len|
    dy = $d[x] + len
    if !$d[y] || dy < $d[y]
      $d[y] = dy
      if !inq[y]
        q << y
        inq[y] = true
      end
    end
  end
  inq[x] = false
end

$v[0] = true
dfs(0, 0, 0, 0)
puts "#{$send} #{$path.unshift(0) * '->'} #{$back}"
