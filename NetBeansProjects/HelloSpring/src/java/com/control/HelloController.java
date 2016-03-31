/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.control;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.AbstractController;

/**
 *
 * @author sanit
 */
public class HelloController extends AbstractController
{

    private String message;
    public HelloController()
    {
    }

    protected ModelAndView handleRequestInternal(HttpServletRequest request, HttpServletResponse response)
            throws Exception
    {
        return new ModelAndView("welcomePage", "welcomeMessage", message);
    }

    public void setMessage(String message)
    {
        this.message=message;
    }
}
