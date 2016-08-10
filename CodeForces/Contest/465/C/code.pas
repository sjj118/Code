var
  n,p,i:longint;
  s:array[-1..1002]of char;

  procedure next(x:longint);
  var
    i,j:longint;
  begin
    if x=n then begin
	  for i:=ord(s[x]) to ord('a')+p-1 do begin
	    s[x]:=chr(i);
	    if (s[x]<>s[x-1])and(s[x]<>s[x-2]) then begin
		  for j:=1 to n do write(s[j]);
		  halt;
		end;
	  end;
	end
	else begin
	  for i:=ord(s[x]) to ord('a')+p-1 do begin
	    s[x]:=chr(i);
	    if (s[x]<>s[x-1])and(s[x]<>s[x-2]) then begin
	      next(x+1);
		  s[x+1]:='a';
		end;
	  end;
	end;
  end;
begin
  readln(n,p);
  for i:=1 to n do read(s[i]);
  s[n]:=chr(ord(s[n])+1);
  next(1);
  writeln('NO');
end.
