import Maharashtra.PuneCity.Pune;
import Maharashtra.PuneCity.Urulikanchan;
import Maharashtra.MumbaiCity.MumbaiCity;
class Tourism
{
    public static void main(String A[])
    {
        System.out.println("Welcome to Maharashtra Tourism");

    MumbaiCity mobj = new MumbaiCity();
    Pune pobj = new Pune();
    Urulikanchan uobj = new Urulikanchan();


    mobj.DisplayMumbai();
    pobj.DisplayPune();
    uobj.DisplayUrulikanchan();
    
    }

    
}