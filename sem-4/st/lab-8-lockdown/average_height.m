function avg = average_height(heights)
  s = 0;
  for i = 1:length(heights)
    s = s + height_to_cm([heights(i, 1) heights(i, 2)]);
  end
  mean = s / length(heights);
  avg = cm_to_height(mean);
end

function cm = height_to_cm(height)
  cm = 100 * height(1) + height(2);
end

function height = cm_to_height(cm)
  height = [floor(cm/100), rem(cm, 100)];
end