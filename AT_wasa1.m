s = serial('COM16','BaudRate',115200); 
fopen(s);
tx='AT';
tx1=char(13);
tx2=char(10);
fprintf(s, '%s', sprintf('%s%s%s', tx, tx1, tx2));
out = fscanf(s);
out
for k=1:5
      out = fscanf(s);
      out
end
