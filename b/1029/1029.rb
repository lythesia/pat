#!/usr/bin/env ruby

s1, s2 = gets.chomp, gets.chomp
raise "fuck" if not s1.chars respond_to? :- # fuck PAT not support array substraction?
puts (s1.upcase.chars - s2.upcase.chars).uniq.join
