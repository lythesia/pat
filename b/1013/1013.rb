#!/usr/bin/env ruby

# case 4 TLE
require 'prime'
m, n = gets.split.map(&:to_i)
Prime.take(n).drop(m-1).each_slice(10) { |a| puts a * ' ' }
