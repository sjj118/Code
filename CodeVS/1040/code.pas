var
  n,p,k,i,j,l,m,s,t:longint;
  d:array[1..6]of string;
  c,c1:string;
  w:array[1..201,1..200]of longint;
  f:array[0..40,0..200]of longint;
  
  function startwith(full,start:string):boolean;
  begin
    if pos(start,full)=1 then startwith:=true else startwith:=false;
  end;
  
  function max(a,b:longint):longint;
  begin
    if a>b then max:=a else max:=b;
  end;
begin
  readln(n);
  for t:=1 to n do begin
    fillchar(f,sizeof(f),0);
    readln(p,k);
	readln(c);
	for i:=2 to p do begin
	  readln(c1);
	  c:=c+c1;
	end;
	readln(s);
	for i:=1 to s do readln(d[i]);
	for i:=1 to 20*p do w[i+1,i]:=0;
	for i:=20*p downto 1 do begin
	  for j:=i downto 1 do begin
	    w[j,i]:=w[j+1,i];
		c1:=copy(c,j,i-j+1);
		for l:=1 to s do begin
		  if startwith(c1,d[l])then begin
		    inc(w[j,i]);
			break;
		  end;
		end;
	  end;
	end;
	for i:=1 to k do begin
	  for j:=i to 20*p do begin
	    for l:=i-1 to j-1 do begin
		  f[i,j]:=max(f[i,j],f[i-1,l]+w[l+1,j]);
		end;
	  end;
	end;
	writeln(f[k,20*p]);
  end;
end.
