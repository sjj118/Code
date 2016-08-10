var
  a,s:array[1..20]of longint;
  n,i,j,max,min,m:longint;
begin
  n:=0;
  repeat
	  inc(n);
	  read(a[n]);
  until a[n]=0;
  dec(n);
  for i:=1 to n do begin
	s[i]:=1;
  end;
  for i:=1 to n-1 do begin
	for j:=i+1 to n do begin
	  if(a[i]>a[j])and(s[j]<=s[i])then begin
		s[j]:=s[i]+1;
	  end;
	end;
  end;
  max:=0;
  for i:=1 to n do if(s[i]>max)then begin
	max:=s[i];
	j:=i;
  end;
  writeln(max);
  for i:=1 to n do begin
	s[i]:=1;
  end;
  for i:=1 to n-1 do begin
	for j:=i+1 to n do begin
	  if(a[i]<=a[j])and(s[j]<=s[i])then begin
		s[j]:=s[i]+1;
	  end;
	end;
  end;
  min:=0;
  for i:=1 to n do if(s[i]>min)then begin
	min:=s[i];
	j:=i;
  end;
  writeln(min);
end.
