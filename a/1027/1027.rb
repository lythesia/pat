#!/usr/bin/env ruby

puts "##{gets.split.map { |x| x.to_i.to_s(13).upcase.rjust(2, '0') }.join}"
