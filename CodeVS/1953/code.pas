var
  r:array[2..200]of boolean;
  n,i,j:longint;
begin
  readln(n);
  for i:=2 to trunc(sqrt(n)) do begin
    if not r[i] then begin
	  for j:=2 to n div i do begin
	    r[i*j]:=true;
	  end;
	end;
  end;
  for i:=2 to n do if not r[i] then write(i,' ');
end.
