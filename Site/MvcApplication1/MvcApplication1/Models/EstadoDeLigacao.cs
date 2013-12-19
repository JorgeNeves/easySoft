using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MvcApplication1.Models
{
    public class EstadoDeLigacao
    {

        public int EstadoDeLigacaoID { get; set; }
        public string Estado { get; set; }
    }
}