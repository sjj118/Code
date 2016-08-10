{
ID: sjj22451
LANG: PASCAL
PROB: crypt1
}
var
  n,i,j,x,ans,a1,a2,a3,b1,b2:longint;
  t:array[0..9]of boolean;
  a,b:array[1..4]of longint;
  c,d:array[1..5]of longint;
  e:array[1..6]of longint;
  flag:boolean;
begin
  assign(input,'crypt1.in');reset(input);assign(output,'crypt1.out');rewrite(output);
  readln(n);
  for i:=1 to n do begin
    read(x);
	t[x]:=true;
  end;
  for a1:=1 to 9 do if t[a1] then begin
    a[1]:=a1;
    for a2:=1 to 9 do if t[a2] then begin
	  a[2]:=a2;
      for a3:=1 to 9 do if t[a3] then begin
	    a[3]:=a3;
        for b1:=1 to 9 do if t[b1] then begin
		  b[1]:=b1;
          for b2:=1 to 9 do if t[b2] then begin
		    b[2]:=b2;
		    fillchar(c,sizeof(c),0);
		    fillchar(d,sizeof(d),0);
		    for i:=1 to 3 do begin
			  c[i]:=c[i]+a[i]*b[1];
			  c[i+1]:=c[i]div 10;
			  c[i]:=c[i]mod 10;
		    end;
			for i:=2 to 4 do begin
			  d[i]:=d[i]+a[i-1]*b[2];
			  d[i+1]:=d[i]div 10;
			  d[i]:=d[i]mod 10;
		    end;
			flag:=true;
			for i:=1 to 3 do if not t[c[i]] then flag:=false;
			for i:=2 to 4 do if not t[d[i]] then flag:=false;
            if c[4]>0 then flag:=false;
            if d[5]>0 then flag:=false;
			if flag then begin
			  fillchar(e,sizeof(e),0);
			  for i:=1 to 4 do begin
			    e[i]:=e[i]+c[i]+d[i];
				e[i+1]:=e[i] div 10;
				e[i]:=e[i] mod 10;
			  end;
			  for i:=1 to 4 do if not t[e[i]] then flag:=false;
              if e[5]>0 then flag:=false;
			  if flag then inc(ans);
			end;
		  end;
	    end;
	  end;
	end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
