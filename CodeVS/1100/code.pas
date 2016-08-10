var
	n,i,p1,p2:longint;
	h,s1,v,l,k,t1,t2:real;
	
	function uptru(a:real):longint;
	begin
		uptru:=trunc(a);
		if uptru<a then inc(uptru);
	end;

        function tru(a:real):longint;
        begin
                tru:=trunc(a);
                if tru>a then dec(tru);
        end;

        function min(a,b:longint):longint;
        begin
                if a>b then exit(b) else exit(a);
        end;

        function max(a,b:real):real;
        begin
                if a>b then exit(a) else exit(b);
        end;

        function get:longint;
        begin
                if p1<0 then p1:=0;
                if p2<0 then p2:=-1;
                if p1>n-1 then p1:=n;
                if p2>n-1 then p2:=n-1;
                writeln(p2-p1+1);
        end;
begin
	readln(h,s1,v,l,k,n);
	t1:=sqrt(max((h-k-0.00001)/5,0));
	t2:=sqrt(h/5);
	p1:=uptru(s1-t2*v-0.00001);
	p2:=tru(s1+l-t1*v);
	get;
end.
