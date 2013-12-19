using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcApplication1.Models;
using MvcApplication1.DAL;

namespace MvcApplication1.Controllers
{
    public class ProfileController : Controller
    {
        private easySoftContext db = new easySoftContext();

        //
        // GET: /Profile/

        public ActionResult Index()
        {
            string name = HttpContext.User.Identity.Name;
            DbSet users = db.UserProfiles;
            
            return View(db.UserProfiles.Find());
        }

        //
        // GET: /Profile/Details/5

        public ActionResult Details(int id = 0)
        {
            UserProfile userprofile = db.UserProfiles.Find(id);
            if (userprofile == null)
            {
                return HttpNotFound();
            }
            return View(userprofile);
        }
        public string Show(string name)
        {
            return name;
        }
        
       
    }
}