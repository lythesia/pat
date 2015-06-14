#!/usr/bin/env ruby

class Rec
  attr_accessor :mon, :time, :on
  def initialize(s)
    @time = s[0].split(":").map(&:to_i)
    @mon = @time.shift
    @on = s[1] == "on-line"
  end

  def to_time
    "%02d:%02d:%02d" % @time
  end
end

toll = gets.split.map(&:to_i)
n = gets.chomp.to_i
lst = Hash.new { |h, k| h[k] = [] }
n.times do
  name, *s = gets.chomp.split
  lst[name] << Rec.new(s)
end

lst.keys.sort.each do |p|
  tot = 0
  last = nil
  lst[p].sort_by { |x| x.time }.each do |x|
    if last and last.on and !x.on
      printf "%s %02d\n" % [p, x.mon] if tot == 0
      f, s = last.time, x.time
      mins = (s[0] - f[0])*1440 + (s[1] - f[1])*60 + (s[2] - f[2])
      hours, cur = (s[0] - f[0])*24 + (s[1] - f[1]), f[1]
      fee = 0
      hours.times do
        fee += toll[cur]*60
        cur = (cur + 1)%24
      end
      fee += toll[s[1]]*s[2] - toll[f[1]]*f[2]
      printf "%s %s %d $%.2f\n" % [last.to_time, x.to_time, mins, 1.0*fee/100]
      tot += fee
    end
    last = x
  end
  printf "Total amount: $%.2f\n" % [1.0*tot/100] if tot > 0
end
