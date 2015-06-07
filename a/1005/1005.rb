#!/usr/bin/env ruby

NUM = %w[ zero one two three four five six seven eight nine ]
puts gets.chomp.chars.map { |c| c.ord - '0'.ord }.reduce(:+).to_s.chars.map { |c| NUM[c.ord - '0'.ord] } * ' '
