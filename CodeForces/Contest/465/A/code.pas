var
  n,i:longint;
  s:string;
begin
  readln(n);
  readln(s);
  i:=1;
  while s[i]='1' do inc(i);
  if i>n then dec(i);
  writeln(i);
end.
