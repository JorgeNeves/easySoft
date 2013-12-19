using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MvcApplication1.Models
{
    public class Estado_Humor
    {

        public int Estado_HumorID { get; set; }
        public string Sentimento { get; set; }
    }
}