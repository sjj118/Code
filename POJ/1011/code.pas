var
	n,i,m,sum:longint;
	a:array[1..64]of longint;
	b:array[1..64]of boolean;
	
	procedure qsort;

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(1,n);
    end;
	
	function go(t,k,l:longint):boolean;
	var
		i:longint;
	begin
		if (k-1)*m=sum then exit(true);
		if l=m then exit(go(0,k+1,0));
		if a[n]+l>m then exit(false);
		for i:=t+1 to n do if (not b[i])and(l+a[i]<=m) then begin
			if i<>t+1 then if (a[i]=a[i-1])and(not b[i-1]) then continue;
			b[i]:=true;
			if go(i,k,l+a[i]) then exit(true);
			b[i]:=false;
			if l=0 then exit(false);
		end;
		exit(false);
	end;
begin
	readln(n);
	while n<>0 do begin
		for i:=1 to n do read(a[i]);
		qsort;
		sum:=0;
		for i:=1 to n do sum:=sum+a[i];
		for m:=a[1] to sum do if sum mod m=0 then begin
			fillchar(b,sizeof(b),false);
			if go(0,1,0) then begin
				writeln(m);
				break;
			end;
		end;
		readln(n);
	end;
end.
