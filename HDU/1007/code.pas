type
	point=record
		x,y:real;
	end;
var
	n,i,j:longint;
	a:array[1..100000]of point;
	
	procedure qsort;

    procedure sort(l,r: longint);
      var
         i,j:longint;
         m:real;
		 t:point;
      begin
         i:=l;
         j:=r;
         m:=a[(l+r) div 2].y;
         repeat
           while a[i].y<m do
            inc(i);
           while m<a[j].y do
            dec(j);
           if not(i>j) then
             begin
                t:=a[i];
                a[i]:=a[j];
                a[j]:=t;
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
	
	function dis(a,b:point):real;
	begin
		exit(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
	end;
	
	function min(a,b:real):real;
	begin
		if a<b then exit(a) else exit(b);
	end;
	
	function solve(l,r:longint):real;
	var
		mid,i,j:longint;
	begin
		if l=r then exit(maxlongint);
		mid:=(l+r)div 2;
		solve:=min(solve(l,mid),solve(mid+1,r));
		for i:=mid downto l do begin
			if a[i].y<a[mid+1].y-solve then break;
			for j:=mid+1 to r do begin
				if a[j].y-solve>a[mid].y then break;
				if abs(a[i].y-a[j].y)>solve then continue;
				solve:=min(solve,dis(a[i],a[j]));
			end;
		end;
	end;

begin
	readln(n);
	while n<>0 do begin
		for i:=1 to n do readln(a[i].x,a[i].y);
		qsort;
		writeln(solve(1,n)/2:0:2);
		readln(n);
	end;
end.
