var
  la,lb,lc,i,j,t,x:longint;
  h:int64;
  a,b:array[1..100000]of longint;
  c:array[1..200000]of longint;
begin
  readln(la,lb,lc,t);
  for i:=1 to la do begin
    read(x);
	inc(a[x]);
  end;
  for i:=1 to lb do begin
    read(x);
	inc(b[x]);
  end;
  for i:=1 to lc do read(c[i]);
  for i:=1 to 100000 do begin
    if a[i]>0 then begin
      for j:=1 to lc do begin
	    h:=h+a[i]*b[c[j]-i];
	  end;
	end;
  end;
  write(h/la/lb:0:10,' ');
  if t<>0 then begin
    h:=0;
    for i:=1 to 100000 do begin
      if a[i]>0 then begin
        for j:=1 to lc do begin
	      h:=h+a[i]*b[c[j] xor i];
	    end;
	  end;
    end;
	write(h/la/lb:0:10);
  end;
end.
